import boto3

ec2 = boto3.client('ec2')

subnetIds = []
subnets = ec2.describe_subnets()

for subnet in subnets['Subnets']:
        subnetIds.append(subnet['SubnetId'])


n = 1
for id in subnetIds:
        instance = ec2.run_instances(
                ImageId = 'ami-0277155c3f0ab2930',
                InstanceType = 't2.micro',
                SecurityGroupIds = ['sg-069b4a86612101500'],
                MaxCount = 1,
                MinCount = 1,
                KeyName = 'ec2_web1',
                SubnetId = id,
                TagSpecifications = [{'ResourceType':'instance', 'Tags':[{'Key':'Name', 'Value':f'VM{n}'}]}])
        n += 1
        print("Instance ID: " + instance["Instances"][0]["InstanceId"])
        print("Subnet ID: " + instance["Instances"][0]["SubnetId"])
        print("Private IP Address" + instance["Instances"][0]["PrivateIpAddress"])
        print("------------------------------")
